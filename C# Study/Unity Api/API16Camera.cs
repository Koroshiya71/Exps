using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class API16Camera : MonoBehaviour
{
    private Camera mainCamera;
    void Start()
    {
        //mainCamera=GameObject.Find("MainCamera").GetComponent<Camera>();
        mainCamera = Camera.main;
    }

    void Update()
    {
        Ray ray=mainCamera.ScreenPointToRay(Input.mousePosition);
        //RaycastHit hit;
        //bool isCollider = Physics.Raycast(ray, out hit);
        //if(isCollider)
        //    print(hit.collider);

        ray = mainCamera.ScreenPointToRay(new Vector3(200, 200, 0));
        Debug.DrawRay(ray.origin,ray.direction*10,Color.blue);
    }
}
