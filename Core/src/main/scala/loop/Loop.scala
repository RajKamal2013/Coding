package loop

import scala.util.control.Breaks.{break, breakable}

object Loop {
  def main(args: Array[String]): Unit = {
    println("Loop Testing");
    val numbers: List[Int] = List(1, 2, 3, 4, 5, 6, 7, 8);

    for (number <- numbers) println(1 * number);
    val doubleNumbers = for (number <- numbers) yield {
      2 * number
    }
    println(doubleNumbers)
  }
}
