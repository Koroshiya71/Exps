using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class API13Random : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //print(Random.Range(233,777));//不包含最大值
        //print(Random.Range(0,1f));
        Random.InitState((int)System.DateTime.Now.Ticks);//如果使用同一种子，则随机数序列永远相同
        //即使不手动设置随机数种子，unity依旧会每次初始化时确保随机数序列不同
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Space))
            print(Random.Range(4,100));
    }
}
