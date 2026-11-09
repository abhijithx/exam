package com.example.foodapp;

import android.os.Bundle;
import android.content.Intent;
import android.widget.*;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    EditText username, password;
    Button login;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        username = findViewById(R.id.username);
        password = findViewById(R.id.password);
        login = findViewById(R.id.login);

        login.setOnClickListener(v -> {

            if (username.getText().toString().isEmpty() ||
                    password.getText().toString().isEmpty()) {

                Toast.makeText(this, "Enter details", Toast.LENGTH_SHORT).show();

            } else {

                Intent i = new Intent(MainActivity.this, HomeActivity.class);
                startActivity(i);
            }
        });
    }
}