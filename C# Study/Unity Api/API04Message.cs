using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class API04Message : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //广播给当前物体与所有子物体
        //BroadcastMessage("Test");
        //仅限本物体
        //SendMessage("Test");
        //发送当前物体以及它的所有父亲，不仅是当前父物体，只要层级比它高，都会调用
        SendMessageUpwards("Test");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
