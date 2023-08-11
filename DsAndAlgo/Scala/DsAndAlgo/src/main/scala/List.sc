/*https://github.com/vkostyukov/scalacaster/blob/master/src/collection/List.scala*/

abstract sealed class  SList[+T] {
  def isEmpty:Boolean
  def head:T
  def tail:SList[T]
  def ::[U >: T](a:U):SList[U]

  override def toString: String = {
    def loop(h:T, t:SList[T], s:String):String =
      if (!t.isEmpty) loop(t.head, t.tail, s + h + ", ")
      else s + h

    if (isEmpty) "SList[]"
    else "SList[" + loop(head, tail, "") + "]"
  }

  def fail(m:String) = throw new NoSuchElementException(m)

  def length():Int =
    if (isEmpty)  0
    else 1 + tail.length()

  def prepend[U>: T](data:U):SList[U] = Cons(data, this)

  def append[U>: T](data:U):SList[U] = if (isEmpty) Cons(data, Nil) else Cons(head, tail.append(data))

  def insert[U>: T](data:U, pos:Int = -1):SList[U] = {
    if (pos == -1) append(data)
    else
      if (isEmpty) Cons(data, Nil)
      else if (pos == 0) prepend(data)
      else Cons(head, tail.insert(data, pos - 1))
  }
  /*
  def slice[start:Int, end:Int]:SList[T] = {


  }
  */
  /*
  def insert[U>: T](pos:Int, data:U):SList[U] =
  def getData(pos:Int):T
  def getIdx(data:T):Int
  def concat(xs:SList[T]):SList[T]
  def remove()
  def contains()
  def foreach()
  def map()
  def fold()
  def reverse()
  def shuffle()
  def length()
  */
}
case object Nil extends SList[Nothing] {
  def isEmpty = true
  def head:Nothing = throw new NoSuchElementException("Nil Head")
  def tail:Nothing = throw new NoSuchElementException("Nil Tail")
  override def ::[U >: Nothing](a: U): SList[U] = Cons(a, Nil)
}


case class Cons[T] (head:T, tail:SList[T] = Nil) extends SList[T] {
  def isEmpty = false
  override def ::[U>:T](a:U):SList[U] = Cons(a, head::tail)
}

object SList {
  def make[T](x:T, xs:SList[T] = Nil):SList[T] = Cons(x, xs)
  def apply[T] (x1:T, x2:T):SList[T] = new Cons(x1, new Cons(x2, Nil))
  def apply[T]() = Nil
  def apply[T](args:T* ):SList[T] = if(args.isEmpty) Nil else Cons(args.head, apply(args.tail: _*))
}

val x: SList[String] = Nil
var mylist = SList(1,2,5,6,7,0)
mylist = mylist.prepend(-1)
println(mylist)
mylist = mylist.append(100)
println(mylist)
mylist = mylist.insert(101)
println(mylist)
mylist = mylist.insert(50, 4)
println(mylist)
println(mylist.length())




