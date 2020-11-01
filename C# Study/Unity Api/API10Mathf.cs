using System.Collections;
using System.Collections.Generic;
using System.Net.WebSockets;
using UnityEditor;
using UnityEngine;

public class API10Mathf : MonoBehaviour
{
    public Transform cube;
    public float t = 1;
    public float speed=5;
    // Start is called before the first frame update
    void Start()
    {
        //print(Mathf.Deg2Rad);//角度转弧度
        //print(Mathf.Rad2Deg);//弧度转角度
        //print(Mathf.Infinity);//正无穷
        //print(Mathf.NegativeInfinity);//负无穷
        //print(Mathf.PI);//PI
        //print(Mathf.Epsilon);//极小浮点数 
        ////ceil向上取整返回值为float，ceilToInt返回值为int
        ////floor向下取整返回值为float,floorToInt返回值为int
        
        //print(Mathf.ClosestPowerOfTwo(280));//取得与该数最接近的2的N次幂
        //print(Mathf.ClosestPowerOfTwo(17));
        //print(Mathf.Max(1,2));
        //print(Mathf.Max(1,2,5,3,10));
        //print(Mathf.Min(1,2));
        //print(Mathf.Min(1,2,5,3,10));
        //print(Mathf.Pow(4,3));
        //print(Mathf.Sqrt(3));
    }

    private int hp = 100;

    void TakeDamage()
    {
        hp -= 9;
        hp = Mathf.Clamp(hp, 0, 100);
    }
    // Update is called once per frame
    void Update()
    {
        ////cube.position=new Vector3(Mathf.Clamp(Time.time,1.0f,3.0f),0,0);
        //print(Mathf.Clamp(Time.time, 1.0f, 3.0f));
        //float x = cube.position.x;
        //float newX = Mathf.Lerp(x, 10, Time.deltaTime);差值运动，先快后慢
        //float newX = Mathf.MoveTowards(x, 10, 0.02f*speed);匀速运动
        //cube.position=new Vector3(newX,0,0);

        //cube.position=new Vector3(Mathf.PingPong(speed*Time.time,10),0,0);//0-10之间运动
        cube.position=new Vector3(5+Mathf.PingPong(speed*Time.time,5),0,0);//5-10之间运动
    }
}
