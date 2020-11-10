using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerCC : MonoBehaviour
{
    private CharacterController cc;

    public float speed = 3;
    // Start is called before the first frame update
    void Start()
    {
        cc = GetComponent<CharacterController>();
    }

    // Update is called once per frame
    void Update()
    {
        float h = Input.GetAxis("Horizontal");
        float v = Input.GetAxis("Vertical");
        cc.SimpleMove(new Vector3(h, 0, v) * speed);//有重力影响
        //cc.Move(new Vector3(h, 0, v) * (speed * Time.deltaTime));//无重力影响

        print(cc.isGrounded);
    }

    private void OnControllerColliderHit(ControllerColliderHit hit)
    {
        print(hit.collider);
    }
}
