package DS.List

object ListTest {

    def main(args:Array[String]):Unit = {
      println("I am testing List now")

      var slist = new SLinkList[Int]()
      for (idx <- 0 to 20) {
        slist.insert(idx)
      }

      println("head:" + slist.top().toString)

      for (idx <- 20  to 25) {
        slist.prepend(idx)
      }

      for (idx <- 25  to 30) {
        slist.append(idx)
      }

      println(slist)

      for (idx <- 0 to 10 by 3) {
        slist.remove(idx)
      }

      println(slist)

      slist.reverse()

      println(slist)
    }

}
