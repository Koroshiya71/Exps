using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class API05GetComponent : MonoBehaviour
{
    public GameObject target;
    // Start is called before the first frame update
    void Start()
    {
        Attack atk=target.GetComponent<Attack>();
        Transform t = target.GetComponent<Transform>();

        print(t);
        print(atk);
        print("-----------------");
        Attack[] atks = target.GetComponents<Attack>();
        print(atks.Length);
        print("-----------------");

        atks = target.GetComponentsInChildren<Attack>();
        foreach (Attack a in atks)
        {
            print(a);
        }
        print("-----------------");
        atks = target.GetComponentsInParent<Attack>();
        foreach (var a in atks)
        {
         print(a);   
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
