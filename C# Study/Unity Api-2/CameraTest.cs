using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraTest : MonoBehaviour
{
    private Camera cam;
    // Start is called before the first frame update
    void Start()
    {
        cam = Camera.main;
    }

    // Update is called once per frame
    void Update()
    {
        Ray ray = cam.ScreenPointToRay(Input.mousePosition);
        //Debug.DrawRay(ray.origin,ray.direction);
        //Debug.DrawLine(ray.origin,ray.origin+ray.direction*100);
        RaycastHit hit;
        bool isCollider = Physics.Raycast(ray, out hit);
        print(hit.collider);
    }
}
