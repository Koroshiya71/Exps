using System;
using UnityEngine;

public class API01EventFunction : MonoBehaviour
{
    public Component rb;

    private void Awake()//即使脚本禁用了，依旧调用
    {
        print("awake");
    }
    
    private void Reset()
    {
        print("reset");
    }

    // Start is called before the first frame update
    private void Start()
    {
        print("start");
    }

    // Update is called once per frame
    private void Update()
    {
        print("update");
    }

    private void FixedUpdate()
    {
        print("fixedUpdate");
    }

    private void LateUpdate()
    {
        print("lateUpdate");
    }

    private void OnEnable()
    {
        print("Enable");
    }

    private void OnDisable()
    {
        print("disabled");
    }

    private void OnApplicationPause(bool pauseStatus)//即使脚本禁用了，依旧调用
    {
        print("pause");
    }
}