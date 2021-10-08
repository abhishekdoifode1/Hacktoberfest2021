defmodule FizzBuzz do
  def build(file_name) do
    file_name
    |> File.read()
    |> handle_file_read()
  end

  defp handle_file_read({:ok, numbers}) do
    result =
      numbers
      |> String.split(",")
      |> Enum.map(&convert_envaluate_numbers/1)

    {:ok, result}
  end

  defp handle_file_read({:error, msg}), do: {:error, "Error reading file: #{msg}"}

  defp convert_envaluate_numbers(elem) do
    elem
    |> String.to_integer()
    |> evaluate()
  end

  defp evaluate(number) when rem(number, 3) == 0 and rem(number, 5) == 0, do: :fizbuzz
  defp evaluate(number) when rem(number, 3) == 0, do: :fizz
  defp evaluate(number) when rem(number, 5) == 0, do: :buzz
  defp evaluate(number), do: number
end
