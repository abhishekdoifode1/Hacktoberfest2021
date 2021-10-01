import kotlinx.coroutines.delay
import kotlinx.coroutines.launch
import kotlinx.coroutines.runBlocking

fun main() = runBlocking{
    launch {
        delay(1000L)
        println("Coroutines!")
    }
    println("Hello,")
    delay(2000L)
}