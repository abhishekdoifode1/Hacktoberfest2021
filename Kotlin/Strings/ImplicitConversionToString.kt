fun main(args: Array<String>) {
    println("Hello" + 9)
    println("Hello" + 'a')
    println("Hello" + 9 + 'a')
    // println(9 + "Hello") // Unlike java, kotlin don't convert to String
    // if number appears in the beginning

    println('a' + "Hello")

    // println(9 + 'a' + "Hello")
    println('a' + 9 + "Hello")

    // Even conversion to character doesn't work if number appears in the
    // beginning.
    // println(9 + 'a')
    println('a' + 9)
}
