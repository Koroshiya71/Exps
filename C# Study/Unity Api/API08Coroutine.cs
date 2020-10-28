using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class API08Coroutine : MonoBehaviour
{
    public GameObject go;
    private IEnumerator ie=null;
    void Start()
    {
        //print("The World");
        ////ChangeColor();
        //StartCoroutine(ChangeColor());
        ////协程方法开启后，会继续运行下面的代码，不会等协程方法运行结束才继续执行
        //print("TokiyoTomare");
    }

    void Update()
    {
        //if (Input.GetKeyDown(KeyCode.Space))
        //{
        //    StartCoroutine(nameof(Fade));
        //}

        //if (Input.GetKeyDown(KeyCode.S))
        //{
        //    StopCoroutine(nameof(Fade));
        //}

        if (Input.GetKeyDown(KeyCode.Space))
        {
            ie = Fade();
            StartCoroutine(ie);
        }

        if(Input.GetKeyDown(KeyCode.S))
            StopCoroutine(ie);
    }

    IEnumerator Fade()
    {

        while (true)
        {
            //go.GetComponent<MeshRenderer>().material.color=new Color(i,i,i,i);
            Color color = go.GetComponent<MeshRenderer>().material.color;
            Color newColor = Color.Lerp(color, Color.red, 0.02f);
            go.GetComponent<MeshRenderer>().material.color = newColor;
            yield return new WaitForSeconds(0.02f);
            if (Mathf.Abs(Color.red.g - newColor.g) <= 0.01f)
                break;
        }

        yield return null;

    }
    //Coroutines
    //1,返回值是IEnumerator
    //2，返回参数的时候使用yield return null/0;
    //3,协程方法的调用StartCoroutine(methodName());
    IEnumerator ChangeColor()
    {
        print("changeColor");
        yield return  new WaitForSeconds(3);
        go.GetComponent<MeshRenderer>().material.color=Color.blue;
        print("changeColor");
        yield return null;
    }
}
