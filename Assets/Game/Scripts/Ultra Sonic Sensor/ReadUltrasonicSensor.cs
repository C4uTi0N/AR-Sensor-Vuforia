using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Uduino;
using TMPro;
using UnityEngine.UI;

public class ReadUltrasonicSensor : MonoBehaviour
{
    UduinoManager uduino;
    UltrasonicSensorDistance ultrasonicSensorDistance;
    public TextMeshProUGUI distanceText;
    float distance;

    void Start()
    {
        uduino = UduinoManager.Instance;
        ultrasonicSensorDistance = GetComponent<UltrasonicSensorDistance>();
        ultrasonicSensorDistance.CalibrateDistance();
        StartCoroutine(ReadSensor());
    }

    IEnumerator ReadSensor()
    {
        while (true)
        {
            print("Reading sensor value... ");
            uduino.sendCommand("readSensorValue");
            uduino.OnValueReceived += DataReceived;
            ultrasonicSensorDistance.CheckDistance(distance);
            yield return new WaitForSeconds(0.1f);
        }
    }

    public void DataReceived(string data, UduinoDevice board)
    {
        distance = float.Parse(data);
        distanceText.text = data;


        if (ultrasonicSensorDistance.isCalibrating)
        {
            ultrasonicSensorDistance.OnDataChanged = float.Parse(data);
        }
    }
}
