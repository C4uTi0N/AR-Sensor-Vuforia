using System.Collections;
using System.Collections.Generic;
using Uduino;
using UnityEngine;
using UnityEngine.UI;

public class UltrasonicSensorDistance : MonoBehaviour
{
    private float distance;

    public Button calibrationButton;
    [Range(0.5f, 1f)] public float sensorSensitivity = 0.9f;
    public int calibrationTime = 5;

    public bool isCalibrating = false;
    [SerializeField] private float defaultDistanceAverage;
    [SerializeField] private List<float> distanceSamples = new List<float>();


    public void CalibrateDistance()
    {
        StartCoroutine(CalibrateDefaultDistance());
    }

    IEnumerator CalibrateDefaultDistance()
    {
        print("Calibrating Ultrasonic Sensor...");
        calibrationButton.interactable = false;
        isCalibrating = true;
        distanceSamples.Clear();

        yield return new WaitForSeconds(calibrationTime);

        defaultDistanceAverage = 0;
        foreach (float distance in distanceSamples)
        {
            defaultDistanceAverage += distance;
        }
        defaultDistanceAverage /= distanceSamples.Count;
        isCalibrating = false;
        calibrationButton.interactable = true;
        print("Calibration done!");
    }

    public void CheckDistance(float _distance)
    {
        if (!isCalibrating)
        {
            if (_distance < (defaultDistanceAverage * sensorSensitivity))
            {
                print("Object detected in front of sensor!");
            }

            if (_distance > (defaultDistanceAverage * 1.1))
            {
                Debug.LogWarning("Current distance is more than 10% greater than expected, please recalibrate!");
            }
        }
    }

    public float OnDataChanged
    {
        get { return distance; }
        set
        {
            if (distance != value)
            {
                distance = value;
                distanceSamples.Add(distance);
            }
        }
    }
}
