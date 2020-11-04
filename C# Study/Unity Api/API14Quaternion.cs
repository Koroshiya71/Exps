using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Serialization;

public class API14Quaternion : MonoBehaviour
{
    [FormerlySerializedAs("cube")] public Transform player;

    public float rotSpeed = 1;
    public Transform enemy;
    // Start is called before the first frame update
    void Start()
    {
        
        //print(player.eulerAngles);
        //var rotation = player.rotation;
        //print(rotation);

        //player.eulerAngles=new Vector3(45,45,45);//两者等效，四元数和欧拉角可以互相转换
        //rotation = Quaternion.Euler(new Vector3(45, 45, 45));
        //player.rotation = rotation;
        //print(rotation.eulerAngles);

        

    }

    // Update is called once per frame
    void Update()
    {
        Vector3 dir = enemy.position - player.position;
        dir.y = 0;
        Quaternion target = Quaternion.LookRotation(dir);
        player.rotation = Quaternion.Slerp(player.rotation, target, Time.deltaTime*rotSpeed);
    }
}
