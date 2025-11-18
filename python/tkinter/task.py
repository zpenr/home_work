import tkinter as tk
from tkinter import messagebox
import json

def save_results():
    name = name_entry.get().strip()
    favorite_game = game_entry.get().strip()
    hours = hours_entry.get().strip()
    
    if not name or not favorite_game or not hours:
        messagebox.showerror("Ошибка", "Пожалуйста, заполните все поля!")
        return
      
    # Создаем словарь с данными
    survey_data = {
        "name": name,
        "favorite_game": favorite_game,
        "hours_per_week": hours
    }
    

    try:
        with open("game_survey.json", "r", encoding="utf-8") as f:
            all_data = json.load(f)
    except FileNotFoundError:
        all_data = []
        
        # Добавляем новые данные
    all_data.append(survey_data)
        
        # Сохраняем обратно в файл
    with open("game_survey.json", "w", encoding="utf-8") as f:
        json.dump(all_data, f, ensure_ascii=False, indent=2)
        
        # Показываем сообщение об успехе
    messagebox.showinfo("Успех", "Анкета сохранена!\nСпасибо за участие!")
        
        # Очищаем поля
    name_entry.delete(0, tk.END)
    game_entry.delete(0, tk.END)
    hours_entry.delete(0, tk.END)


# Создаем главное окно
root = tk.Tk()
root.title("Анкета геймера")
root.geometry("500x500")

title_label = tk.Label(
    root, 
    text="Анкета предпочтений в играх",
    font=("Arial", 14, "bold"),
    pady=10
)
title_label.pack()




tk.Label(root, text="Ваше имя:", font=("Arial", 10)).grid(row=0, column=0, sticky="w", pady=8)
name_entry = tk.Entry(root, width=30, font=("Arial", 10))
name_entry.grid(row=0, column=1, pady=8, padx=10)

tk.Label(root, text="Любимая игра:", font=("Arial", 10)).grid(row=1, column=0, sticky="w", pady=8)
game_entry = tk.Entry(root, width=30, font=("Arial", 10))
game_entry.grid(row=1, column=1, pady=8, padx=10)

tk.Label(root, text="Часов в неделю:", font=("Arial", 10)).grid(row=2, column=0, sticky="w", pady=8)
hours_entry = tk.Entry(root, width=30, font=("Arial", 10))
hours_entry.grid(row=2, column=1, pady=8, padx=10)


button_frame = tk.Frame(root)
button_frame.pack(pady=20)

save_btn = tk.Button(
    button_frame,
    text="Сохранить анкету",
    command=save_results,
    bg="#4CAF50",
    fg="white",
    font=("Arial", 10),
    width=15
)
save_btn.pack(side="left", padx=5)


root.mainloop()