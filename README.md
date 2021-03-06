# OOP_Workflow_Executor
Требуется реализовать приложение Workflow Executor.
Workflow – вычислительная схема, состоящая из набора вычислительных блоков и связей между ними. Программе подается workflow, описанный в файле.

В данной задаче рассматривается единственный тип workflow – линейный, т.е. конвейер.

Список блоков, используемых в схеме (набор блоков расширяем):
readfile <filename>  – считывание текстового файла в память, целиком. 
Вход – отсутствует, выход – текст.
writefile <filename> – запись текста в файл.
Вход – текст, выход – отсутствует. 
grep <word> – выбор из входного текста строк, разделенных символами переноса строки, содержащих заданное слово <word>.
Вход – текст, выход – текст. 
sort – лексикографическая сортировка входного набора строк.
Вход – текст, выход – текст.
replace <word1> <word2> – замена слова <word1> словом <word2> во входном тексте.
Вход – текст, выход – текст.
dump <filename> - сохранить пришедший текст в указанном файле и передать дальше.
Вход – текст, выход – текст.

Формат входного файла:
desc # описание блоков схемы
id1 = block1
id2 = block2
…
idN = blockN
csed
idA -> idB -> idC -> … -> idZ # описание структуры схемы

Где:
desc, csed – ключевые слова, ограничивающие раздел описания блоков workflow.
id1 … idN – целые, неотрицательные, неповторяющиеся числа.
block1 … blockN – блоки из списка блоков, с обязательными параметрами.
idA, idB … idZ – числа, принадлежащие множеству id1…idN. Могут повторяться, длина конвейера – неограничена.
-> – ключевое слово, обозначающее связь вычислительных узлов.

Пример файла Workflow:
workflow.txt
desc 
1 = readfile in_file.txt
2 = writefile out_file.txt
3 = sort
10 =  replace word1 word2
csed
1 -> 3 -> 10 -> 3 -> 2

Ограничения на вычислительную схему:
Блоки должны содержать нужное количество параметров.
Узлы схемы должны корректно соединяться, то есть тип данных на входе узла должен совпадать с типом данных предыдущего узла. Это означает, что чтение/запись файлов не может быть в середине схемы.
