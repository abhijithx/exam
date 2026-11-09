package com.example.foodapp;

import android.os.Bundle;
import android.content.SharedPreferences;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class HistoryActivity extends AppCompatActivity {

    TextView historyText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_history);

        historyText = findViewById(R.id.historyText);

        SharedPreferences sp = getSharedPreferences("FoodHistory", MODE_PRIVATE);

        String history = sp.getString("history", "");

        if (history.isEmpty()) {

            historyText.setText("No Previous Orders Found");

        } else {

            historyText.setText(history);

        }
    }
}
