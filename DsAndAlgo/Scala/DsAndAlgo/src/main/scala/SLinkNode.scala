package DS.List
class SLinkNode[T](var data:T, var next:SLinkNode[T]=null) {
  def getNext:SLinkNode[T] = this.next;;
  def getData():T = this.data;
}
