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
import com.amaze.filemanager.database.models.utilities.History;
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
public final class HistoryEntryDao_Impl implements HistoryEntryDao {
  private final RoomDatabase __db;

  private final EntityInsertionAdapter<History> __insertionAdapterOfHistory;

  private final EntityDeletionOrUpdateAdapter<History> __updateAdapterOfHistory;

  private final SharedSQLiteStatement __preparedStmtOfDeleteByPath;

  private final SharedSQLiteStatement __preparedStmtOfClear;

  public HistoryEntryDao_Impl(RoomDatabase __db) {
    this.__db = __db;
    this.__insertionAdapterOfHistory = new EntityInsertionAdapter<History>(__db) {
      @Override
      public String createQuery() {
        return "INSERT OR REPLACE INTO `history` (`_id`,`path`) VALUES (nullif(?, 0),?)";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, History value) {
        stmt.bindLong(1, value._id);
        if (value.path == null) {
          stmt.bindNull(2);
        } else {
          stmt.bindString(2, value.path);
        }
      }
    };
    this.__updateAdapterOfHistory = new EntityDeletionOrUpdateAdapter<History>(__db) {
      @Override
      public String createQuery() {
        return "UPDATE OR ABORT `history` SET `_id` = ?,`path` = ? WHERE `_id` = ?";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, History value) {
        stmt.bindLong(1, value._id);
        if (value.path == null) {
          stmt.bindNull(2);
        } else {
          stmt.bindString(2, value.path);
        }
        stmt.bindLong(3, value._id);
      }
    };
    this.__preparedStmtOfDeleteByPath = new SharedSQLiteStatement(__db) {
      @Override
      public String createQuery() {
        final String _query = "DELETE FROM history WHERE path = ?";
        return _query;
      }
    };
    this.__preparedStmtOfClear = new SharedSQLiteStatement(__db) {
      @Override
      public String createQuery() {
        final String _query = "DELETE FROM history";
        return _query;
      }
    };
  }

  @Override
  public Completable insert(final History instance) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        __db.beginTransaction();
        try {
          __insertionAdapterOfHistory.insert(instance);
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
        }
      }
    });
  }

  @Override
  public Completable update(final History instance) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        __db.beginTransaction();
        try {
          __updateAdapterOfHistory.handle(instance);
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
        }
      }
    });
  }

  @Override
  public Completable deleteByPath(final String path) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        final SupportSQLiteStatement _stmt = __preparedStmtOfDeleteByPath.acquire();
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
          __preparedStmtOfDeleteByPath.release(_stmt);
        }
      }
    });
  }

  @Override
  public Completable clear() {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        final SupportSQLiteStatement _stmt = __preparedStmtOfClear.acquire();
        __db.beginTransaction();
        try {
          _stmt.executeUpdateDelete();
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
          __preparedStmtOfClear.release(_stmt);
        }
      }
    });
  }

  @Override
  public Single<List<History>> list() {
    final String _sql = "SELECT `history`.`_id` AS `_id`, `history`.`path` AS `path` FROM history";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 0);
    return RxRoom.createSingle(new Callable<List<History>>() {
      @Override
      public List<History> call() throws Exception {
        final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
        try {
          final int _cursorIndexOfId = CursorUtil.getColumnIndexOrThrow(_cursor, "_id");
          final int _cursorIndexOfPath = CursorUtil.getColumnIndexOrThrow(_cursor, "path");
          final List<History> _result = new ArrayList<History>(_cursor.getCount());
          while(_cursor.moveToNext()) {
            final History _item;
            final String _tmpPath;
            _tmpPath = _cursor.getString(_cursorIndexOfPath);
            _item = new History(_tmpPath);
            _item._id = _cursor.getInt(_cursorIndexOfId);
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
