using UnityEngine;
using System.IO.Ports;
using UnityEngine.Video;

public class SerialVideoController : MonoBehaviour
{
    public string portName = "COM8"; // Change this to your Arduino's COM port
    public int baudRate = 9600;

    private VideoPlayer videoPlayer;

    public VideoClip video1;
    public VideoClip video2;
    public VideoClip video3;
    public VideoClip video4;
    public VideoClip video5;
    public VideoClip video6;
    public VideoClip video7;
    public VideoClip video8;

    private SerialPort serialPort;
    private string lastInput = ""; // Store the last input received
    private float lastInputTime = 0f; // Track the time of the last input
    private float videoTimeout = 40f; // Timeout in seconds for no input

    void Start()
    {
        // Initialize the serial port
        serialPort = new SerialPort(portName, baudRate);
        serialPort.Open();

        // Get the VideoPlayer component
        videoPlayer = GetComponent<VideoPlayer>();

        // Set an initial video to display
        if (video1 != null)
        {
            PlayVideo(video1);
        }
    }

    void Update()
    {
        // Check for serial input
        if (serialPort.IsOpen && serialPort.BytesToRead > 0)
        {
            string input = serialPort.ReadLine().Trim();

            // Only act if the input has changed
            if (input != lastInput)
            {
                lastInput = input;
                lastInputTime = Time.time; // Update the last input time

                switch (input)
                {
                    case "1":
                        PlayVideo(video1);
                        break;
                    case "2":
                        PlayVideo(video2);
                        break;
                    case "3":
                        PlayVideo(video3);
                        break;
                    case "4":
                        PlayVideo(video4);
                        break;
                    case "5":
                        PlayVideo(video5);
                        break;
                    case "6":
                        PlayVideo(video6);
                        break;
                    case "7":
                        PlayVideo(video7);
                        break;
                    case "8":
                        PlayVideo(video8);
                        break;
                    default:
                        Debug.LogWarning("Unknown input: " + input);
                        break;
                }
            }
        }

        // Check for timeout (no new input for `videoTimeout` seconds)
        if (Time.time - lastInputTime > videoTimeout)
        {
            if (video4 != null && videoPlayer.clip != video4)
            {
                PlayVideo(video4);  // Play video4 if no input
            }
            else if (!videoPlayer.isPlaying)  // Keep video4 looping if it stops
            {
                videoPlayer.Play();
            }
        }

    }

    void PlayVideo(VideoClip clip)
    {
        if (clip != null && videoPlayer.clip != clip)
        {
            videoPlayer.Stop();
            videoPlayer.clip = clip;
            videoPlayer.Play();
        }
    }

    void OnApplicationQuit()
    {
        if (serialPort != null && serialPort.IsOpen)
        {
            serialPort.Close();
        }
    }
}
