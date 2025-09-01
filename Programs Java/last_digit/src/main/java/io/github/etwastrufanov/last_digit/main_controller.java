package io.github.etwastrufanov.last_digit;

// Импортируем модель
import io.github.etwastrufanov.last_digit.main_model;

// Всякие модули
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import java.io.IOException;


public class main_controller {
    // Поля ввода
    public TextField input_area;
    public TextField output_area;

    // Обработчик нажатия кнопки
    @FXML
    public void on_calc_click(MouseEvent mouseEvent) {
        // Обрабатываемое число
        double value = 0;
        // Получаем его через try, чтобы не было ошибки если есть мусор в поле ввода
        try {
            // Красим текст в красный
            input_area.setStyle("-fx-text-fill: black;");
            // Получаем число
            value = Double.parseDouble(input_area.getText());
            // Расчитываем и округляем
            value = Math.round(main_model.last_digit(value)*100.0)/100.0;
            // Выводим число
            output_area.setText(Double.toString(value));
        } catch (NumberFormatException e) {
            // Если есть мусор, то красим текст
            input_area.setStyle("-fx-text-fill: red;");
        }

    }

    // Выводим сообщение о программе
    public void on_menu_click(ActionEvent actionEvent) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("О программе");
        alert.setHeaderText(null);
        alert.setContentText("Предназначена для рассчёта площади равностороннего треугольника");
        alert.showAndWait();
    }
}
