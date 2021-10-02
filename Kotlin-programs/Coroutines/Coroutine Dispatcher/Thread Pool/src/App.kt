import kotlinx.coroutines.*

@ObsoleteCoroutinesApi
fun main() = runBlocking<Unit> {
    val dispatcher = newFixedThreadPoolContext(3, "myPool")

    launch(dispatcher) {
        println("Starting in ${Thread.currentThread().name}")
        delay(1000)
        println("Resuming in ${Thread.currentThread().name}")
    }.start()
}