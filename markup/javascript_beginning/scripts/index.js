    function Task1() {
        let n = +prompt("Задача 1. Введите N:", 50);
        let output = "Квадраты:\n";
        let i = 1;
        while (i * i <= n) {
            output += (i * i) + " ";
            i++;
        }
        alert(output);
    }

    function Task2() {
        let a = +prompt("Задача 2. a:", -5);
        let b = +prompt("Задача 2. b:", 12);
        let sum = 0, count = 0;
        for (let i = a; i <= b; i++) {
            if (i % 3 === 0) { sum += i; count++; }
        }
        alert("Среднее: " + sum/count);
    }

    function Task3() {
        let n = +prompt("Задача 3. Число:", 64);
        if (n < 1) { alert("NO"); return; }
        while (n > 1 && n % 2 === 0) n /= 2;
        alert(n === 1 ? "YES" : "NO");
    }

    function Task4() {
        let str = prompt("Задача 4. Строка:", "font-size");
        let words = str.split('-');
        let res = words[0];
        for (let i = 1; i < words.length; i++) {
            if(words[i]) res += words[i].charAt(0).toUpperCase() + words[i].slice(1);
        }
        alert(res);
    }