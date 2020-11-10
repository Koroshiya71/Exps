using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class API17Application : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        print(Application.dataPath);
        print(Application.streamingAssetsPath);
        print(Application.persistentDataPath);
        print(Application.temporaryCachePath);

        print(Application.identifier);
        print(Application.companyName);
        print(Application.productName);
        print(Application.installerName);
        print(Application.installMode);
        print(Application.isEditor);
        print(Application.isFocused);
        print(Application.isMobilePlatform);
        print(Application.isPlaying);
        print(Application.platform);
        print(Application.unityVersion);
        print(Application.version);
        print(Application.runInBackground);

        Application.Quit();
        Application.OpenURL("www.bilibili.com");

    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
