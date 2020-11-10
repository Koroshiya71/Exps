using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TouchTest : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Touch touch1;//easyTouch
        //print(Input.touches.Length);//多指触摸时，根据触摸顺序返回touches数组
        if (Input.touches.Length > 0)
        {
            touch1 = Input.touches[0];
            TouchPhase phase = touch1.phase;//Began:开始触碰,Ended:触碰结束,Moved:手指滑动,Stationary:暂停滑动,Canceled:??

        }
    }
}
