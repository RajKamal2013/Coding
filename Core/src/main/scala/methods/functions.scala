package methods



object functions {
  def funcA(number: Int): Int = {
    if (number < 0) 0
    else number + 1
  }
  def main(args: Array[String]): Unit = {
    val x = {
      funcA(10)
    }
    println(x)
   
   val plusOne = (x:Int) => (x + 1)
   println(plusOne(10)) 
  }

}
