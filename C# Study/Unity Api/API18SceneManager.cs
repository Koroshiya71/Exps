using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class API18SceneManager : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        print(SceneManager.sceneCount);
        print(SceneManager.sceneCountInBuildSettings);

        print(SceneManager.GetActiveScene().name);
        print(SceneManager.GetSceneAt(0).name);

        SceneManager.activeSceneChanged += OnActiveSceneChanged;
        SceneManager.sceneLoaded += OnSceneLoaded;

    }

    void OnSceneLoaded(Scene a, LoadSceneMode mode)
    {
        print(a.name+" "+mode);
    }
    void OnActiveSceneChanged(Scene A, Scene B)
    {
        print(A.name);
        print(B.name);
    }
    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            SceneManager.LoadScene(0);
            //SceneManager.LoadScene("02 - MenuScene");
            //SceneManager.LoadScene(SceneManager.GetSceneByBuildIndex(1).name);//只有当场景加载过后才能通过这种方式获取
        }
    }

    
}
