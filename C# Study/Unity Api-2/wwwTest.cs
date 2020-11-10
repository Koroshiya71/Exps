using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class wwwTest : MonoBehaviour
{
    // Start is called before the first frame update
    public string url = "https://s1.zerochan.net/Hatsune.Miku.600.3118103.jpg";
    IEnumerator Start()
    {
        using (WWW www = new WWW(url))
        {
            yield return www;
            CanvasRenderer renderer = GetComponent<CanvasRenderer>();
            renderer.SetTexture(www.texture); 
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
