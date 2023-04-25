![Proyecto Final!!](https://i.imgur.com/QMVxhX7.png)
<h1 align="center"> PROYECTO SIMPLE SHELL :paperclip:</h1>
<h2 align="rigth">Description:  <img src="https://cdn-icons-png.flaticon.com/128/868/868684.png" width=45 align=center></h2>
<div> This is a simple UNIX command interpreter program, which replicates the functionality of a basic shell, using C language. It was developed for the 1st term final project at Holberton School. </div>
<h2 align="rigth">Installation: :desktop_computer: </h2>
<div> Clone this repository into your working directory. <br>
You must compile with 

```
gcc -Wall -Wextra -Werror -pedantic -Wno-format.
``` 
</div>
<h2 align="rigth">It can be used: </h2>
<div> The resulting program can run stand-alone, either in interactive or non-interactive mode.</div>
<h2 align="rigth">Modes</h2>
<h3 align="rigth">Interactive Mode </h3>
<div>it mimics the behavior of a basic shell, shows a prompt, which waits for the commands you enter and executes them, you can exit with "exit" or ctrl-D. <br> 
To run the shell is like this: <br>

```
$ ./hsh
```
</div>
 <h3 align="rigth">Non-Interactive Mode </h3>
<div> using the command "echo" and "|", execute the command.<br>
 shown in the following example:

```
echo "ls" | ./shell
```
- Important note: <br>
The program will exit after finishing your desired command(s). </div>
<h2 align="rigth">Examples </h2>
<div> Example in non-interactive mode:<br>

```
$ /bin/pwd
/home/vagrant/shell
```
</div>
