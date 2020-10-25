using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class API03GameObject : MonoBehaviour
{
    public GameObject go;
    void Start()
    {
     //1,第一种创建方法
     //GameObject go=new GameObject();   
     //2,第二种创建方法，根据prefab或另外一种游戏物体克隆
     //GameObject.Instantiate(go);
     //3,第三种创建方法，根据预设类型创造一个预设的物体
     go=GameObject.CreatePrimitive(PrimitiveType.Cube);

     go.AddComponent<Rigidbody>();//添加刚体组件
     //go.AddComponent<API01EventFunction>();//添加自定义脚本

     //print(go.activeInHierarchy);
     //go.SetActive(false);
     //print(go.activeInHierarchy);
     //print(go.tag);

     //print(go.name);
     //print(go.GetComponent<Rigidbody>().name); //通过游戏物体.name和游戏物体上的组件.name获取的都是游戏物体的名字
     //Destroy(go, 3);
     //Light lt = FindObjectOfType<Light>();
     //lt.enabled = false;
     //Transform[] ts = FindObjectsOfType<Transform>();
     //foreach(Transform t in ts)
     //    print(t.name);

     //go=GameObject.Find("Main Camera");
     //go=GameObject.FindGameObjectWithTag("MainCamera");
     GameObject[] gos = GameObject.FindGameObjectsWithTag("MainCamera");
     //go.SetActive(false);
     gos[0].SetActive(false);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
