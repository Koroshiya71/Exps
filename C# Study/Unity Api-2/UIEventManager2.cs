using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;


public class UIEventManager2 : MonoBehaviour,
    IBeginDragHandler,IDragHandler,IEndDragHandler,IDropHandler
{
    //public void OnPointerDown(PointerEventData eventData)//只有当raycastTarget被勾选时才生效
    //{
    //    print("iPointerDown");
    //}

    //public void OnPointerClick(PointerEventData eventData)
    //{
    //    print("iPointerClick");

    //}

    //public void OnPointerUp(PointerEventData eventData)
    //{
    //    print("iPointerUp");
    //}

    //public void OnPointerEnter(PointerEventData eventData)
    //{
    //    print("iPointerEnter");

    //}

    public void OnBeginDrag(PointerEventData eventData)
    {
        print("onBeginDrag");

    }


    public void OnDrag(PointerEventData eventData)
    {
        print("onDrag");

    }

    public void OnEndDrag(PointerEventData eventData)
    {
        print("onEndDrag");

    }

    public void OnDrop(PointerEventData eventData)//只有当拖拽结束并且鼠标仍在物体上时触发
    {
        print("onDrop");

    }
}
