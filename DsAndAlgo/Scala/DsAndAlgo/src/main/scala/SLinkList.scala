package DS.List

import scala.util.control.Breaks

class  SLinkList[T]  {
  var head:SLinkNode[T] = null;
  var curr:SLinkNode[T] = null;
  var len:Int = 0;

  /* Helper APIs */
  def isEmpty(): Boolean = {
    if (head == null) {
      true
    } else {
      false
    }
  }

  def size(): Int = {
    this.len
  }

  def top():T = {
    assert(head != null)
    getData(0)
  }

  def getData(pos: Int): T = {
    assert(pos >= 0 && pos < len && head != null);
    var temp:SLinkNode[T] = head;
    var idx:Int = 0;

    while (idx != pos) {
      temp = temp.getNext;
    }

    assert(temp != null);
    temp.data;
  }

  def getIdx(data:T):Int = {
    assert(head != null);
    var temp:SLinkNode[T] = head;
    var idx = 0;

    while(temp != null) {
      if ((temp.getData()).equals(data)) {
        return idx;
      } else {
        idx = idx + 1;
      }
    }

    assert(temp == null);
    idx;
  }

  /* Iterative API */

  def cur(): T = {
    this.curr.getData;
  }

  def next():Unit  = {
    this.curr = this.curr.getNext;
  }

  def move(pos:Int) :Unit = {
    assert(pos >= 0 && pos < len);
    this.curr = this.head;
    var idx:Int = 0;

    while (idx != pos) {
      this.curr = this.curr.getNext;
    }

  }

  def reset():Unit = {
    this.curr = this.head;
  }

  def last:Unit = {
    this.curr = this.head;

    while(this.curr.getNext != null) {
      this.curr = this.curr.getNext;
    }

  }

  /* Search API */

  def contains(data:T):Boolean = {
    var temp:SLinkNode[T] = this.head;

    while(temp != null) {
      if ((temp.getData())equals()) {
        return true;
      } else {
          temp = temp.getNext;
      }
    }

    false;
  }

  /* Insert APIs */
  def insert(data:T):Unit = {
    var newNode  = new SLinkNode[T](data, null)

    head match {
      case null => {
        head = newNode
        curr = head
      }

      case _ => {
        newNode.next = curr.next
        curr.next = newNode;
        curr = newNode;
      }
    }
    len = len + 1;
  }

  def insert(data:T, pos:Int): Unit = {
    var newNode = new SLinkNode[T](data, null)
    assert(pos >= 0 && pos < len)

    pos match {
      case 0 => {
        newNode.next = head;
        head = newNode
      }
      case _ => {
        var temp = head
        var idx = 0;
        while(idx < pos) {
          idx = idx + 1
          temp = temp.next;
        }
        newNode.next = temp.next
        temp.next= newNode
      }
    }

    len = len + 1
  }

  def append(data:T): Unit = {
      insert(data, len - 1)
  }

  def prepend(data:T): Unit = {
      insert(data, 0)
  }

  /* remove APIs */
  def remove(data:T):Unit = {
    var prev = head;
    var temp = head;

    val loopBreak = new Breaks;
    assert(data != null)
    loopBreak.breakable {
      while (temp != null) {
        if (temp.data.equals(data)) {
          if (temp equals (prev)) {
            head = temp.next
          } else {
            prev.next = temp.next;
          }
          if (curr equals (temp)) {
            curr = temp.next
          }
          len = len - 1
          loopBreak.break()
        } else {
          prev = temp
          temp = temp.next
        }
      }
    }
  }


  def pop(data:T) = {
        assert(head != null);
        if (curr.equals(head)) {
          curr = head.next
        }
        head = head.next
        len = len - 1
  }

  def dequeue(data:T) :Unit = {
    assert(head != null)
    var data = getData(len - 1)
    remove(data)
  }

  def remove(): Unit = {
      var data = curr.data
      remove(data)
  }

  /* Misc */
  def reverse():Unit = {
    var curNode:SLinkNode[T] = null
    var revList :SLinkNode[T] = null
    var nextNode :SLinkNode[T] = null;

    curNode = head;
    while (curNode != null) {
      nextNode = curNode.next
      curNode.next = revList;
      revList = curNode
      curNode = nextNode
    }

    head = revList;
    curr = head
  }

  override def toString(): String = {
    var strbuf = new StringBuilder("")
    var itrNode = head
    while (itrNode != null) {
      strbuf = strbuf.append(new StringBuilder(itrNode.data.toString + " "))
      itrNode = itrNode.next
    }
    var str = strbuf.toString()
    str
  }

  def clear():Unit = {
    while (head != null) {
      head = head.next
    }
    curr = null
    len = 0
  }
}
