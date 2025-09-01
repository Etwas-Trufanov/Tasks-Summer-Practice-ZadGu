package io.github.etwastrufanov.calc_with_precision;

// Импортируем модель

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;

// Ненавижу слово считать

// Класс контроллера
public class MainController {
    @FXML
    // Поле результата
    public TextField ResultOutput;
    // Поле ввода точности
    public TextField PrecisionInput;

    // Обработчик кнопки
    @FXML
    public void OnCalcClicked(ActionEvent actionEvent) {
        // Результат
        double outValue = 0.0;
        // Точность
        double precisionValue = 0.0;
        // Через try считываем значение, в случае ошибки красим текст в красный
        try {
            PrecisionInput.setStyle("-fx-text-fill: black;");
            precisionValue = Double.parseDouble(PrecisionInput.getText());
        } catch (NumberFormatException e) {

            PrecisionInput.setStyle("-fx-text-fill: red;");
            return;
        }
        // Расчитываем значение
        outValue = MainModel.calc(precisionValue);
        // Выводим
        ResultOutput.setText(String.valueOf(outValue));
    }

    // Справка
    @FXML
    public void OnAboutClicked(ActionEvent actionEvent) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("О программе");
        alert.setHeaderText(null);
        alert.setContentText("Программа для просчёта числа с заданной точностью");

        alert.showAndWait();
    }
}
