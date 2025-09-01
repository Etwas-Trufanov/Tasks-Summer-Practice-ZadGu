module io.github.etwastrufanov.last_digit {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.desktop;


    opens io.github.etwastrufanov.last_digit to javafx.fxml;
    exports io.github.etwastrufanov.last_digit;
}