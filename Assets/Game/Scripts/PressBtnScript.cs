using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class PressBtnScript : MonoBehaviour
{
    public string btnName;
    public string btnVal;

    public TextMeshPro displayText; 

    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.touchCount > 0 && Input.touches[0].phase == TouchPhase.Began)
        {
            Ray ray = Camera.main.ScreenPointToRay(Input.GetTouch(0).position);
            RaycastHit Hit;

            if(Physics.Raycast(ray, out Hit)){
                btnName = Hit.transform.name;
                switch (btnName)
                {
                    case "btn1":
                        //Hit.collider.gameObject.SetActive(false);
                        btnVal = "1";
                        displayText.text += btnVal;
                        break;

                    case "btn2":
                        btnVal = "2";
                        displayText.text += btnVal;
                        Debug.Log("btn 2");
                        Debug.Log(displayText.text);
                        //Hit.collider.gameObject.SetActive(false);
                        break;

                    case "btn3":
                        btnVal = "3";
                        displayText.text += btnVal;
                        Debug.Log("btn 3");
                        Debug.Log(displayText.text);
                       // Hit.collider.gameObject.SetActive(false);
                        break;
                    case "btn4":
                        btnVal = "4";
                        displayText.text += btnVal;
                        Debug.Log("btn 4");
                        Debug.Log(displayText.text);
                        //Hit.collider.gameObject.SetActive(false);
                        break;

                    case "btn5":
                        btnVal = "5";
                        displayText.text += btnVal;
                        Debug.Log("btn 5");
                        Debug.Log(displayText.text);
                        //Hit.collider.gameObject.SetActive(false);
                        break;

                    case "btn6":
                        btnVal = "6";
                        displayText.text += btnVal;
                        Debug.Log("btn 6");
                        Debug.Log(displayText.text);
                        //Hit.collider.gameObject.SetActive(false);
                        break;
                }
            }
        }

        if(displayText.text.Length == 4)
        {
            if(displayText.text == "1234")
            {
                displayText.text = "yes!";
            }
            else
            {
                displayText.text = "";
            }
        }
    }
}
