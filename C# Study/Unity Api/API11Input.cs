using System;
using UnityEngine;

public class API11Input : MonoBehaviour
{
    public Transform cube;

    public float speed = 1;
    // Start is called before the first frame update
    private void Start()
    {
    }

    // Update is called once per frame
    private void Update()
    {
        //if (Input.GetKeyDown(KeyCode.Space))
        //    print("keydown");
        //if (Input.GetKey(KeyCode.Space))
        //    print("key");
        //if (Input.GetKeyUp(KeyCode.Space))
        //    print("keyup");
        //if (Input.GetMouseButtonDown(0)) //0：左键，1：右键，2：中键
        //    print("leftMouseButton");
        //if (Input.GetButtonDown("Fire1"))
        //    print("f1");
        //print(Input.GetAxis("Horizontal"));
        //cube.Translate(Vector3.right * (Input.GetAxis("Horizontal") * speed * Time.deltaTime));
        cube.Translate(Vector3.right * (Input.GetAxisRaw("Horizontal") * speed * Time.deltaTime));
        if(Input.anyKeyDown)//检测鼠标和键盘上任意按键
            print("anyKeyDown");

        print(Input.mousePosition);//左下角为坐标原点，单位为像素
    }


}