using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class API09OnMouseEventFunction : MonoBehaviour
{
    //在物体上按下鼠标，即使鼠标离开这个物体它的drag事件依旧会持续调用
    //在哪个物体上按下鼠标，即使鼠标即使离开该物体，它的drag和up事件也是在该物体上触发
    private void OnMouseDown()
    {
        print("down");
    }

    private void OnMouseUp()
    {
        print("up");
    }

    private void OnMouseDrag()
    {
        print("drag");
    }

    private void OnMouseEnter()
    {
        print("enter");
    }

    private void OnMouseExit()
    {
        print("exit");
    }

    private void OnMouseOver()
    {
        print("over");
    }

    //AsButton则只有在按下后，并在同一物体上抬起时触发，如果离开当前物体则不触发
    private void OnMouseUpAsButton()
    {
        print("up as button");
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
