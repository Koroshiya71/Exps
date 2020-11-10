using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Ray ray=new Ray(transform.position,Vector3.forward);
        RaycastHit hit;
        RaycastHit[] hits;
        //bool isCollider=Physics.Raycast(ray,1);//检测碰撞的第一个
        //bool isCollider=Physics.Raycast(ray,out hit);
        //bool isCollider = Physics.Raycast(ray,  Mathf.Infinity, LayerMask.GetMask("Enemy1"));

        bool isCollider = Physics.Raycast(ray, out hit,Mathf.Infinity, LayerMask.GetMask("Enemy1"));
        print(hit.transform);
        //hits=Physics.RaycastAll(ray,Mathf.Infinity);//检测所有射线碰撞到的物体,返回一个hits数组
        print(isCollider);
    }
}
