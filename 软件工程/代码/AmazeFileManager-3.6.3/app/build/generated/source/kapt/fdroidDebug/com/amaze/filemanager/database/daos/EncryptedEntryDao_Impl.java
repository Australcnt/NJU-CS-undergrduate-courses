package com.amaze.filemanager.database.daos;

import android.database.Cursor;
import androidx.room.EmptyResultSetException;
import androidx.room.EntityDeletionOrUpdateAdapter;
import androidx.room.EntityInsertionAdapter;
import androidx.room.RoomDatabase;
import androidx.room.RoomSQLiteQuery;
import androidx.room.RxRoom;
import androidx.room.SharedSQLiteStatement;
import androidx.room.util.CursorUtil;
import androidx.room.util.DBUtil;
import androidx.sqlite.db.SupportSQLiteStatement;
import com.amaze.filemanager.database.models.StringWrapper;
import com.amaze.filemanager.database.models.explorer.EncryptedEntry;
import com.amaze.filemanager.database.typeconverters.EncryptedStringTypeConverter;
import io.reactivex.Completable;
import io.reactivex.Single;
import java.lang.Exception;
import java.lang.Override;
import java.lang.String;
import java.lang.SuppressWarnings;
import java.lang.Void;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;

@SuppressWarnings({"unchecked", "deprecation"})
public final class EncryptedEntryDao_Impl implements EncryptedEntryDao {
  private final RoomDatabase __db;

  private final EntityInsertionAdapter<EncryptedEntry> __insertionAdapterOfEncryptedEntry;

  private final EntityDeletionOrUpdateAdapter<EncryptedEntry> __updateAdapterOfEncryptedEntry;

  private final SharedSQLiteStatement __preparedStmtOfDelete;

  public EncryptedEntryDao_Impl(RoomDatabase __db) {
    this.__db = __db;
    this.__insertionAdapterOfEncryptedEntry = new EntityInsertionAdapter<EncryptedEntry>(__db) {
      @Override
      public String createQuery() {
        return "INSERT OR ABORT INTO `encrypted` (`_id`,`path`,`password`) VALUES (nullif(?, 0),?,?)";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, EncryptedEntry value) {
        stmt.bindLong(1, value.getId());
        if (value.getPath() == null) {
          stmt.bindNull(2);
        } else {
          stmt.bindString(2, value.getPath());
        }
        final String _tmp;
        _tmp = EncryptedStringTypeConverter.fromPassword(value.getPassword());
        if (_tmp == null) {
          stmt.bindNull(3);
        } else {
          stmt.bindString(3, _tmp);
        }
      }
    };
    this.__updateAdapterOfEncryptedEntry = new EntityDeletionOrUpdateAdapter<EncryptedEntry>(__db) {
      @Override
      public String createQuery() {
        return "UPDATE OR ABORT `encrypted` SET `_id` = ?,`path` = ?,`password` = ? WHERE `_id` = ?";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, EncryptedEntry value) {
        stmt.bindLong(1, value.getId());
        if (value.getPath() == null) {
          stmt.bindNull(2);
        } else {
          stmt.bindString(2, value.getPath());
        }
        final String _tmp;
        _tmp = EncryptedStringTypeConverter.fromPassword(value.getPassword());
        if (_tmp == null) {
          stmt.bindNull(3);
        } else {
          stmt.bindString(3, _tmp);
        }
        stmt.bindLong(4, value.getId());
      }
    };
    this.__preparedStmtOfDelete = new SharedSQLiteStatement(__db) {
      @Override
      public String createQuery() {
        final String _query = "DELETE FROM encrypted WHERE path = ?";
        return _query;
      }
    };
  }

  @Override
  public Completable insert(final EncryptedEntry entry) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        __db.beginTransaction();
        try {
          __insertionAdapterOfEncryptedEntry.insert(entry);
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
        }
      }
    });
  }

  @Override
  public Completable update(final EncryptedEntry entry) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        __db.beginTransaction();
        try {
          __updateAdapterOfEncryptedEntry.handle(entry);
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
        }
      }
    });
  }

  @Override
  public Completable delete(final String path) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        final SupportSQLiteStatement _stmt = __preparedStmtOfDelete.acquire();
        int _argIndex = 1;
        if (path == null) {
          _stmt.bindNull(_argIndex);
        } else {
          _stmt.bindString(_argIndex, path);
        }
        __db.beginTransaction();
        try {
          _stmt.executeUpdateDelete();
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
          __preparedStmtOfDelete.release(_stmt);
        }
      }
    });
  }

  @Override
  public Single<EncryptedEntry> select(final String path) {
    final String _sql = "SELECT `encrypted`.`_id` AS `_id`, `encrypted`.`path` AS `path`, `encrypted`.`password` AS `password` FROM encrypted WHERE path = ?";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 1);
    int _argIndex = 1;
    if (path == null) {
      _statement.bindNull(_argIndex);
    } else {
      _statement.bindString(_argIndex, path);
    }
    return RxRoom.createSingle(new Callable<EncryptedEntry>() {
      @Override
      public EncryptedEntry call() throws Exception {
        final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
        try {
          final int _cursorIndexOfId = CursorUtil.getColumnIndexOrThrow(_cursor, "_id");
          final int _cursorIndexOfPath = CursorUtil.getColumnIndexOrThrow(_cursor, "path");
          final int _cursorIndexOfPassword = CursorUtil.getColumnIndexOrThrow(_cursor, "password");
          final EncryptedEntry _result;
          if(_cursor.moveToFirst()) {
            _result = new EncryptedEntry();
            final int _tmp_id;
            _tmp_id = _cursor.getInt(_cursorIndexOfId);
            _result.setId(_tmp_id);
            final String _tmpPath;
            _tmpPath = _cursor.getString(_cursorIndexOfPath);
            _result.setPath(_tmpPath);
            final StringWrapper _tmpPassword;
            final String _tmp;
            _tmp = _cursor.getString(_cursorIndexOfPassword);
            _tmpPassword = EncryptedStringTypeConverter.toPassword(_tmp);
            _result.setPassword(_tmpPassword);
          } else {
            _result = null;
          }
          if(_result == null) {
            throw new EmptyResultSetException("Query returned empty result set: " + _statement.getSql());
          }
          return _result;
        } finally {
          _cursor.close();
        }
      }

      @Override
      protected void finalize() {
        _statement.release();
      }
    });
  }

  @Override
  public Single<List<EncryptedEntry>> list() {
    final String _sql = "SELECT `encrypted`.`_id` AS `_id`, `encrypted`.`path` AS `path`, `encrypted`.`password` AS `password` FROM encrypted";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 0);
    return RxRoom.createSingle(new Callable<List<EncryptedEntry>>() {
      @Override
      public List<EncryptedEntry> call() throws Exception {
        final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
        try {
          final int _cursorIndexOfId = CursorUtil.getColumnIndexOrThrow(_cursor, "_id");
          final int _cursorIndexOfPath = CursorUtil.getColumnIndexOrThrow(_cursor, "path");
          final int _cursorIndexOfPassword = CursorUtil.getColumnIndexOrThrow(_cursor, "password");
          final List<EncryptedEntry> _result = new ArrayList<EncryptedEntry>(_cursor.getCount());
          while(_cursor.moveToNext()) {
            final EncryptedEntry _item;
            _item = new EncryptedEntry();
            final int _tmp_id;
            _tmp_id = _cursor.getInt(_cursorIndexOfId);
            _item.setId(_tmp_id);
            final String _tmpPath;
            _tmpPath = _cursor.getString(_cursorIndexOfPath);
            _item.setPath(_tmpPath);
            final StringWrapper _tmpPassword;
            final String _tmp;
            _tmp = _cursor.getString(_cursorIndexOfPassword);
            _tmpPassword = EncryptedStringTypeConverter.toPassword(_tmp);
            _item.setPassword(_tmpPassword);
            _result.add(_item);
          }
          if(_result == null) {
            throw new EmptyResultSetException("Query returned empty result set: " + _statement.getSql());
          }
          return _result;
        } finally {
          _cursor.close();
        }
      }

      @Override
      protected void finalize() {
        _statement.release();
      }
    });
  }
}
