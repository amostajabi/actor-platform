package im.actor.sdk.controllers.conversation;

import android.content.Intent;
import android.graphics.drawable.ColorDrawable;
import android.os.Build;
import android.os.Bundle;
import android.provider.Settings;
import android.support.v4.app.Fragment;
import android.view.KeyEvent;
import android.view.View;
import android.view.inputmethod.EditorInfo;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import im.actor.sdk.ActorSDK;
import im.actor.sdk.ActorStyle;
import im.actor.sdk.R;
import im.actor.sdk.controllers.activity.BaseActivity;
import im.actor.sdk.util.KeyboardHelper;
import im.actor.sdk.view.TintImageView;
import im.actor.sdk.view.emoji.keyboard.BaseKeyboard;
import im.actor.sdk.view.emoji.keyboard.KeyboardStatusListener;
import im.actor.sdk.view.emoji.keyboard.emoji.EmojiKeyboard;

import static im.actor.sdk.util.ActorSDKMessenger.messenger;

public abstract class ActorEditTextActivity extends BaseActivity {

    //////////////////////////////////
    // Input panel
    //////////////////////////////////

    // Message edit text
    protected EditText messageEditText;
    // Send message button
    protected TintImageView sendButton;
    // Attach button
    protected ImageButton attachButton;
    // Removed from group panel
    protected View inputBlockContainer;

    // Helper for hide/show keyboard
    protected KeyboardHelper keyboardUtils;

    // Emoji keyboard
    protected EmojiKeyboard emojiKeyboard;
    protected ImageView emojiButton;
    protected FrameLayout sendContainer;
    protected TextView inputBlockedText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        getWindow().setBackgroundDrawable(new ColorDrawable(ActorSDK.sharedActor().style.getMainBackgroundColor()));

        // Setting main layout
        setContentView(R.layout.activity_dialog);

        // Setting fragment
        setFragment(savedInstanceState);

        // Message container
        FrameLayout messageContainer = (FrameLayout) findViewById(R.id.fl_send_panel);
        messageContainer.setBackgroundColor(STYLE.getMainBackgroundColor());
        // Message Body
        messageEditText = (EditText) findViewById(R.id.et_message);
        messageEditText.setTextColor(STYLE.getTextPrimaryColor());
        messageEditText.setHintTextColor(STYLE.getTextHintColor());

        // Hardware keyboard events
        messageEditText.setOnKeyListener((view, keycode, keyEvent) -> {
            if (messenger().isSendByEnterEnabled()) {
                if (keyEvent.getAction() == KeyEvent.ACTION_DOWN && keycode == KeyEvent.KEYCODE_ENTER) {
                    onSendButtonPressed();
                    return true;
                }
            }
            return false;
        });

        // Software keyboard events
        messageEditText.setOnEditorActionListener((textView, i, keyEvent) -> {
            if (i == EditorInfo.IME_ACTION_SEND) {
                onSendButtonPressed();
                return true;
            }
            if (i == EditorInfo.IME_ACTION_DONE) {
                onSendButtonPressed();
                return true;
            }
            if (messenger().isSendByEnterEnabled()) {
                if (keyEvent != null && i == EditorInfo.IME_NULL && keyEvent.getAction() == KeyEvent.ACTION_DOWN) {
                    onSendButtonPressed();
                    return true;
                }
            }
            return false;
        });

        // Send Button
        sendButton = (TintImageView) findViewById(R.id.ib_send);
        sendButton.setResource(R.drawable.conv_send);
        sendButton.setOnClickListener(v -> onSendButtonPressed());

        // Attach Button
        attachButton = (ImageButton) findViewById(R.id.ib_attach);
        attachButton.setOnClickListener(v -> onAttachButtonClicked());

        // Kick panel
        inputBlockContainer = findViewById(R.id.kickedFromChat);
        inputBlockContainer.setBackgroundColor(ActorSDK.sharedActor().style.getMainBackgroundColor());
        inputBlockedText = (TextView) inputBlockContainer.findViewById(R.id.kicked_text);
        inputBlockedText.setTextColor(STYLE.getMainColor());

        // Emoji keyboard
        emojiButton = (ImageView) findViewById(R.id.ib_emoji);
        emojiKeyboard = new EmojiKeyboard(this);
        emojiKeyboard.setKeyboardStatusListener(new KeyboardStatusListener() {

            @Override
            public void onDismiss() {
                emojiButton.setImageResource(R.drawable.ic_emoji);
            }

            @Override
            public void onShow() {
                emojiButton.setImageResource(R.drawable.ic_keyboard);
            }

        });
        emojiButton.setOnClickListener(v -> emojiKeyboard.toggle(messageEditText));

        sendContainer = (FrameLayout) findViewById(R.id.sendContainer);

        // Keyboard helper for show/hide keyboard
        keyboardUtils = new KeyboardHelper(this);
    }

    protected void setFragment(Bundle savedInstanceState) {
        if (savedInstanceState == null) {
            getSupportFragmentManager().beginTransaction()
                    .replace(R.id.messagesFragment, onCreateFragment())
                    .commit();
        }
    }

    protected abstract Fragment onCreateFragment();


    protected void onSendButtonPressed() {

    }

    protected void onAttachButtonClicked() {

    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (requestCode == BaseKeyboard.OVERLAY_PERMISSION_REQ_CODE) {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                if (!Settings.canDrawOverlays(this)) {
                    Toast.makeText(this, "Ooops, emoji Keyboard needs overlay permission", Toast.LENGTH_LONG).show();
                } else {
                    emojiKeyboard.showChecked();
                }
            }
        }
        super.onActivityResult(requestCode, resultCode, data);
    }

    @Override
    protected void onPause() {
        super.onPause();
        emojiKeyboard.destroy();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        emojiKeyboard.release();
    }
}
