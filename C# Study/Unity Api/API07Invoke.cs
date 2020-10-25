using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class API07Invoke : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //Invoke(nameof(Attack),3);
        InvokeRepeating(nameof(Attack),4,2);
        CancelInvoke(nameof(Attack));
    }

    void Attack()
    {
        print("Attacking");
    }
    // Update is called once per frame
    void Update()
    {
        bool res = IsInvoking(nameof(Attack));
        print(res);
    }
}
