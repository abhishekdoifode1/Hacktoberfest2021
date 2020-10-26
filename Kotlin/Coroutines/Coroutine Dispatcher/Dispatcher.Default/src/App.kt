import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.runBlocking

fun main() = runBlocking {
    launch {
        // TODO: Implement suspending lambda here
    }

    launch(Dispatchers.Default) {
        // TODO: Implement suspending lambda here
    }

    println("Dispatcher Default")
}