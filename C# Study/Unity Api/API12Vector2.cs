using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class API12Vector2 : MonoBehaviour
{
    // Start is called before the first frame update
    public Vector2 a=new Vector2(2,2);
    public Vector2 target=new Vector2(10,3);
    void Start()
    {
        //Vector2和Vector3都是struct不是class
        //print(Vector2.down);
        //print(Vector2.up);
        //print(Vector2.left);
        //print(Vector2.right);
        //print(Vector2.one);
        //print(Vector2.zero);

        //Vector2 va=new Vector2(2,3),vb=new Vector2(7,7);
        //print(va.magnitude);
        //print(va.sqrMagnitude);
        //print(vb.magnitude);
        //print(vb.sqrMagnitude);

        //print(va.normalized);
        //print(vb.normalized);

        //print(va.x+" "+va.y);
        //print(va[0]+" "+va[1]);

        //transform.position.x = 10;//由于transform是结构体，所以transform.position.x是一个指而不是变量
        //因此无法这样单独对x坐标进行修改

        //所以只能如下进行修改
        //Vector3 pos = transform.position;
        //pos.x = 10;
        //transform.position = pos;

        //Vector2 a = new Vector2(2, 2), b = new Vector2(3, 4),c=new Vector2(3,0);

        //print(Vector2.Angle(a,b));
        //print(Vector2.Angle(a, c));
        //print(Vector2.ClampMagnitude(c, 2));
        //print(Vector2.Distance(b, c));

        //print(Vector2.Lerp(a,b, 0.5f));//2.5 3
        //print(Vector2.LerpUnclamped(a, b, 0.5f));//2.5 3

        //print(Vector2.Lerp(a, b, 2f));//b:3 4
        //print(Vector2.LerpUnclamped(a, b, 2f));//4 6

        //print(Vector2.Max(a,b));
        //print(Vector2.Min(a, b));

        //把二维向量赋值给三维向量，Z轴的值会恒定为0
        //把三维向量赋值给二维向量
    }

    // Update is called once per frame
    void Update()
    {
        a=Vector2.MoveTowards(a,target,Time.deltaTime);
        print(a);
    }
}
