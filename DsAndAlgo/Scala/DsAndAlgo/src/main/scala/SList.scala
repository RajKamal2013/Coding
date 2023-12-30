package DS.List

trait SList[+T] {
  def isEmpty:Boolean
  def head:T
  def tail:SList[T]
}


case object Nil extends SList[Nothing] {
  def isEmpty = true
  def head:Nothing = throw new NoSuchElementException("Nil Head")
  def tail:Nothing = throw new NoSuchElementException("Nil Tail")
}


case class Cons[T] (head:T, tail:SList[T] = Nil) extends SList[T] {
  def isEmpty = false
}

object SList {
  def apply[T] (x1:T, x2:T):SList[T] = new Cons(x1, new Cons(x2, Nil))
}
