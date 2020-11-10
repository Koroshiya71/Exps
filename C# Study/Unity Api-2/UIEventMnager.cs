using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UIEventMnager : MonoBehaviour
{
    public GameObject btn;

    public GameObject slider;

    public GameObject dropDown;

    public GameObject toggle;
    // Start is called before the first frame update
    void Start()
    {
        btn.GetComponent<Button>().onClick.AddListener(btnOnClick);
        slider.GetComponent<Slider>().onValueChanged.AddListener(onSliderChanged);
        dropDown.GetComponent<Dropdown>().onValueChanged.AddListener(onDropDownChanged);
        toggle.GetComponent<Toggle>().onValueChanged.AddListener(onToggleChanged);

    }

    void btnOnClick()
    {
        print("btnOnClick");
    }

    void onSliderChanged(float value)
    {
        print("sliderValue:"+ value);
    }

    void onDropDownChanged(int value)
    {
        print("dropDownChanged"+value);
    }

    void onToggleChanged(bool value)
    {
        print("toggle"+value);
    }
    // Update is called once per frame
    void Update()
    {
        
    }
}
