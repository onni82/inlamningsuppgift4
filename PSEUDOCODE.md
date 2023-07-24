# pseudo code for some functions
 pseudokod för vissa funktioner i inlämningsuppgift 4
 
sökfunktion:
```
FOR i = 0 to the length of list
    IF list[i] = element to search for THEN
        Return i
    END IF
END FOR
```

trimfunktion:
```
DEFINE output string
FOR each character in input string
    IF character = \n OR character = \r
        SKIP to next iteration of FOR
    ELSE output = output + character
    END IF
END FOR
RETURN output
```

booleanfunktion som kollar om man har skrivit in nummer 5 som ska avsluta programmet:
```
IF input = 5
    RETURN true
ELSE
    RETURN false
END IF
```
