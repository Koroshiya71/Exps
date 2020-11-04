using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class API15RigidBody : MonoBehaviour
{
    public Transform enemy;
    public Rigidbody playerRgd;
    public int force;
    public float rotSpeed = 2;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //playerRgd.position = playerRgd.transform.position + Vector3.forward * Time.deltaTime;//受重力影响的position控制,效率更快，性能更好
        //playerRgd.MovePosition(playerRgd.transform.position + Vector3.forward * (Time.deltaTime * 10));

        //Vector3 dir = enemy.position - playerRgd.position;
        //dir.y = 0;
        //Quaternion target = Quaternion.LookRotation(dir);
        //playerRgd.MoveRotation ( Quaternion.Slerp(playerRgd.rotation, target, Time.deltaTime * rotSpeed));

        if(Input.GetKey(KeyCode.Space))
            playerRgd.AddForce(Vector3.forward*force);
    }
}
