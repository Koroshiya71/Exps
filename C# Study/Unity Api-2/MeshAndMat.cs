using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MeshAndMat : MonoBehaviour
{
    public Mesh mesh;

    private Material mat;
    void Start()
    {
        //GetComponent<MeshFilter>().mesh = mesh;
        //print(GetComponent<MeshFilter>().mesh==mesh);//这种方式是进行一次复制再赋值，因此会输出false

        //GetComponent<MeshFilter>().sharedMesh = mesh;
        //print(GetComponent<MeshFilter>().sharedMesh==mesh);//这种方式是直接将其赋值因此返回true

        mat = GetComponent<MeshRenderer>().material;
    }

    // Update is called once per frame
    void Update()
    {
        mat.color = Color.Lerp(mat.color,Color.red,Time.deltaTime);   
    }
}
