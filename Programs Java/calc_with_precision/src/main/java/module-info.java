module io.github.etwastrufanov.calc_with_precision {
    requires javafx.controls;
    requires javafx.fxml;


    opens io.github.etwastrufanov.calc_with_precision to javafx.fxml;
    exports io.github.etwastrufanov.calc_with_precision;
}