package im.actor.core.api.updates;
/*
 *  Generated by the Actor API Scheme generator.  DO NOT EDIT!
 */

import im.actor.runtime.bser.*;
import im.actor.runtime.collections.*;
import static im.actor.runtime.bser.Utils.*;
import im.actor.core.network.parser.*;
import org.jetbrains.annotations.Nullable;
import org.jetbrains.annotations.NotNull;
import com.google.j2objc.annotations.ObjectiveCName;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;
import im.actor.core.api.*;

public class UpdateMessageRead extends Update {

    public static final int HEADER = 0x13;
    public static UpdateMessageRead fromBytes(byte[] data) throws IOException {
        return Bser.parse(new UpdateMessageRead(), data);
    }

    private ApiPeer peer;
    private long startDate;
    private long readDate;

    public UpdateMessageRead(@NotNull ApiPeer peer, long startDate, long readDate) {
        this.peer = peer;
        this.startDate = startDate;
        this.readDate = readDate;
    }

    public UpdateMessageRead() {

    }

    @NotNull
    public ApiPeer getPeer() {
        return this.peer;
    }

    public long getStartDate() {
        return this.startDate;
    }

    public long getReadDate() {
        return this.readDate;
    }

    @Override
    public void parse(BserValues values) throws IOException {
        this.peer = values.getObj(1, new ApiPeer());
        this.startDate = values.getLong(2);
        this.readDate = values.getLong(3);
    }

    @Override
    public void serialize(BserWriter writer) throws IOException {
        if (this.peer == null) {
            throw new IOException();
        }
        writer.writeObject(1, this.peer);
        writer.writeLong(2, this.startDate);
        writer.writeLong(3, this.readDate);
    }

    @Override
    public String toString() {
        String res = "update MessageRead{";
        res += "peer=" + this.peer;
        res += ", startDate=" + this.startDate;
        res += ", readDate=" + this.readDate;
        res += "}";
        return res;
    }

    @Override
    public int getHeaderKey() {
        return HEADER;
    }
}