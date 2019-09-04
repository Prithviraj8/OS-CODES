echo "Enter two nos:"
read num1
read num2
ch=1
while [ $ch -ne 5 ]

do
  echo "\n\nMENU:\n1.ADDITION  \n2:SUBTRACTION \n3:MULTIPLICATION \n4:DIVISION \n5:EXIT"
  echo "Enter the choice"
  read ch

  case $ch in
    1) echo"ADDITION of $num1 and $num2 is "
      a=`expr $num1 + $num2`
      echo $a
      ;;
      2)echo "Subtraction of $num1 and $num2 is: "
        b=`expr $num1 - $num2`
        echo $b ;;
    3)echo "Multiplication of $num1 and $num2 is: "
      c=`expr $num1 \* $num2`
      echo $c ;;
    4)if [ $num2 -eq 0 ]; then
      echo "Division of $num1 and $num2 is not possible."
      else
      echo "Division of $num1 and $num2 is: "
      d=`expr $num1 / $num2`
      echo $d
      fi ;;
    5)echo "Exit" ;;
    *)echo "Invalid choice" ;;
  esac
done
